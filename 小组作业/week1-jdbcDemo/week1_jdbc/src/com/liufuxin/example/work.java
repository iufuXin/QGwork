package com.liufuxin.example;

import com.alibaba.druid.pool.DruidDataSourceFactory;
import pojo.Student;

import javax.sql.DataSource;
import java.io.FileInputStream;
import java.sql.*;
import java.util.*;

//工具类的封装
public class work {
    //私有化构造器
    private work(){ }

    /**
     * 菜单展示界面
     */
    public static void show(){
        System.out.println("A:添加数据");
        System.out.println("B:查询数据");
        System.out.println("C:修改数据");
        System.out.println("D:删除数据");
        System.out.println("E:退出");
    }
    /**
     * 连接数据库
     *
     */
    public static Connection connectionDatabase() throws Exception {
        //1.获取连接
//        String url = "jdbc:mysql://127.0.0.1:3306/dbl1";
//        String username = "root";
//        String password = "Lfx520520";
//        return DriverManager.getConnection(url, username, password);
        //上面这段为常规连接
        //连接池的配置
        //加载配置文件
        Properties prop = new Properties();
        prop.load(new FileInputStream("src/druid.properties"));
        //4.获取连接池对象
        DataSource dataSource = DruidDataSourceFactory.createDataSource(prop);
        //5.获取数据库连接 Connection
        return dataSource.getConnection();
    }

    public static Scanner sc = new Scanner(System.in);
    /**
     * 添加数据
     *
     */
    public static void DataAdd(Connection conn) throws Exception {
        //定义sql语句
        String sql = "insert into studentdata (name,sex,score) values (?,?,?);";
        //获取sql执行的对象
        PreparedStatement pstmt = conn.prepareStatement(sql);
        //输入学生信息
        int cnt;
        int count=0;//用于记录影响的行数
        System.out.println("请输入创建学生信息个数：");
        cnt= sc.nextInt();
        for (int i = 0; i < cnt; i++) {
            System.out.println("请输入学生名字：");
            pstmt.setString(1,sc.next());
            System.out.println("请输入学生性别：");
            pstmt.setString(2, sc.next());
            System.out.println("请输入学生绩点：");
            pstmt.setDouble(3,sc.nextDouble());
            count += pstmt.executeUpdate();
        }
        if ( count >0){
            System.out.println("添加成功，并自动分配学号");
        }
        pstmt.close();
    }

    /**
     * 查询学生信息
     *
     */
    public static void queryAllData(Connection conn) throws Exception {
        //记录用户的选择
        String choose ;
        String sql = null;
        String name;
        PreparedStatement pstmt = null;
        while (true) {
            System.out.println("A.查询个人数据");
            System.out.println("B.查询全部数据");
            System.out.println("C.退出");
            choose=sc.next();
            if ( choose.equals("A")){
                try {
                    System.out.println("请输入你要查询的名字：");
                    sql = "select * from studentdata where name = ?;";
                    name=sc.next();
                    pstmt = conn.prepareStatement(sql);
                    pstmt.setString(1,name);
                    printfData(pstmt);
                } catch (Exception e) {
                    System.out.println("没有该学生！");
                }
            } else if (choose.equals("B")) {
                //定义sql语句
                sql = "select * from studentdata";
                pstmt = conn.prepareStatement(sql);
                printfData(pstmt);
            } else if (choose.equals("C")) {
                break;
            }
        }
        if (pstmt != null) {
            pstmt.close();
        }
    }
    /**
     *
     * 输出数据
     */
    public static void printfData(PreparedStatement pstmt) throws Exception{
        ResultSet rs = pstmt.executeQuery();
        Student stu = null;
        List<Student> stus = new ArrayList<>();
        while (rs.next()) {
            stu = new Student();
            stu.setId(rs.getInt(1));
            stu.setName(rs.getString(2));
            stu.setSex(rs.getString(3));
            stu.setScore(rs.getDouble(4));
            stus.add(stu);
        }
        if ( stus.get(0).getName().equals("")){
            System.out.println("没有该学生");
        } else {
            for (int i = 0; i < stus.size(); i++) {
                System.out.println("————————————————————");
                System.out.println("学生学号为"+stus.get(i).getId());
                System.out.println("学生名字为"+stus.get(i).getName());
                System.out.println("学生性别为"+stus.get(i).getSex());
                System.out.println("学生绩点为"+stus.get(i).getScore());
                System.out.println("————————————————————");
            }
        }
        rs.close();
    }

    /**
     *
     * 修改数据
     * sql = "update studentdata set name = ?,sex = ? where id = ?;"
     */
    public static void UpdateData(Connection conn) throws Exception {
        String sql;
        String choose ;
        String sex;
        PreparedStatement pstm = null;
        while (true) {
            System.out.println("A:修改名字");
            System.out.println("B:修改性别");
            System.out.println("C:修改绩点");
            System.out.println("D:退出");
            System.out.println("注：学号无法进行修改，为系统分配所得！！！");
            choose = sc.next();
            if (choose.equals("A")){
                sql = "update studentdata set name = ? where id = ?";
                pstm = conn.prepareStatement(sql);
                if ( UpdateName(pstm) > 0 ){
                    System.out.println("修改成功~~");
                } else {
                    System.out.println("修改失败，可能是没有该学生");
                }
            } else if (choose.equals("B")) {
                sql = "update studentdata set sex = ? where id = ?;";
                pstm = conn.prepareStatement(sql);
                if ( UpdateSex(pstm) > 0 ){
                    System.out.println("修改成功~~");
                } else {
                    System.out.println("修改失败，可能是没有该学生");
                }
            } else if (choose.equals("C")) {
                sql = "update studentdata set score = ? where id = ?;";
                pstm = conn.prepareStatement(sql);
                if ( UpdateScore(pstm) > 0 ){
                    System.out.println("修改成功~~");
                } else {
                    System.out.println("修改失败，可能是没有该学生");
                }
            } else if ( choose.equals("D")){
                break;
            }
        }
        if (pstm != null) {
            pstm.close();
        }
    }

    /**
     * 修改名字
     *
     */
    public static int UpdateName(PreparedStatement pstmt) throws Exception {
        String name;
        int id;
        System.out.println("请输入学号：");
        id = sc.nextInt();
        System.out.println("请输入修改后的名字：");
        name = sc.next();
        pstmt.setString(1,name);
        pstmt.setInt(2,id);
        return pstmt.executeUpdate();
    }
    /**
     * 修改性别
     *
     */
    public static int UpdateSex(PreparedStatement pstmt) throws Exception {
        String sex;
        int id;
        System.out.println("请输入学号：");
        id = sc.nextInt();
        System.out.println("请输入修改后的性别：");
        sex = sc.next();
        pstmt.setString(1,sex);
        pstmt.setInt(2,id);
        return pstmt.executeUpdate();
    }

    /**
     * 修改绩点
     * @param pstmt
     * @return
     * @throws Exception
     */
    public static int UpdateScore(PreparedStatement pstmt) throws Exception {
        double score;
        int id;
        System.out.println("请输入学号：");
        id = sc.nextInt();
        System.out.println("请输入修改后的绩点：");
        score = sc.nextDouble();
        pstmt.setDouble(1,score);
        pstmt.setInt(2,id);
        return pstmt.executeUpdate();
    }

    /**
     * 删除数据根据学号
     * sql = "delete from studentdata where id = ?;"
     * @param conn
     */
    public static void delectData(Connection conn) throws Exception {
        String sql = "delete from studentdata where id = ?;";
        PreparedStatement pstmt = conn.prepareStatement(sql);
        int num;//用于记录要删除的学生个数
        System.out.println("请输入你要删除的学生的个数：");
        num = sc.nextInt();
        int[] ids = new int[num];
        System.out.println("请输入学号：（如输入超过原输入个数将只拿前面有效值）");
        for (int i = 0; i < ids.length; i++) {
            ids[i] = sc.nextInt();
        }
        for (int i = 0; i < ids.length; i++) {
            pstmt.setInt(1,ids[i]);
            System.out.println(pstmt.executeUpdate()>0 ? "" : ("学号为"+ids[i]+"的学生删除失败，可能是没有该学生"));
        }
        pstmt.close();
    }
}
