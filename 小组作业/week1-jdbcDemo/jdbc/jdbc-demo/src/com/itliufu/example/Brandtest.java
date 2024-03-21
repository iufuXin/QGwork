package com.itliufu.example;

import com.alibaba.druid.pool.DruidDataSourceFactory;
import com.itliufu.pojo.Brand;
import org.junit.Test;

import javax.sql.DataSource;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.Statement;
import java.util.ArrayList;
import java.util.List;
import java.util.Properties;

/**
 * 品牌的增删改查
 *
 */

public class Brandtest {
    /**
     * 查询所有数据
     * 1.SQL:select * from tb_brand
     * 2.参数：不需要
     * 3.集合：list<Brand>;
     *
     */

    @Test
    public void testSelectAll() throws Exception {
        Properties prop = new Properties();
        //prop.load(new FileInputStream("jdbc-demo/src/com/itliufu/src/druid.Properties"));
        prop.load(new FileInputStream("src/com/itliufu/druid.Projecties"));
        //4.获取连接池对象
        DataSource dataSource = DruidDataSourceFactory.createDataSource(prop);
        //5.获取数据库连接 Connection
        Connection conn = dataSource.getConnection();

        //定义sql语句
        String sql = "select * from brand";

        //获取pstmt对象
        PreparedStatement pstmt = conn.prepareStatement(sql);

        ResultSet rs = pstmt.executeQuery();

        List<Brand> brands = new ArrayList<>();
        Brand brand = null;
        while (rs.next()){
            brand = new Brand();
            //获取数据
            brand.setId(rs.getInt("id"));
            brand.setBrandName(rs.getString("brand_name"));
            brand.setCompanyName(rs.getString("company_name"));
            brand.setOrdered(rs.getInt("ordered"));
            brand.setDescription(rs.getString("description"));
            brand.setStatus(rs.getInt("status"));
            //封装对象
            //装载集合
            brands.add(brand);

        }
        System.out.println(brands);
        //释放资源
        rs.close();
        pstmt.close();
        conn.close();
        //System.out.println(System.getProperty("user.dir"));

    }

    /**
     * 添加数据
     * sql:insert into brand (brand_name, company_name, ordered, description, status) values (?,?,?,?,?);
     * @throws Exception
     */


    @Test
    public void testadd() throws Exception {
        String brandName = "香飘飘";
        String companyName = "香飘飘";
        int ordered =2;
        String description = "销量惊人";
        int status =1;

        Properties prop = new Properties();
        //prop.load(new FileInputStream("jdbc-demo/src/com/itliufu/src/druid.Properties"));
        prop.load(new FileInputStream("src/com/itliufu/druid.Projecties"));
        //4.获取连接池对象
        DataSource dataSource = DruidDataSourceFactory.createDataSource(prop);
        //5.获取数据库连接 Connection
        Connection conn = dataSource.getConnection();

        //定义sql语句
        String sql = "insert into brand (brand_name, company_name, ordered, description, status) values (?,?,?,?,?);";

        //获取pstmt对象
        PreparedStatement pstmt = conn.prepareStatement(sql);

        pstmt.setString(1,brandName);
        pstmt.setString(2,companyName);
        pstmt.setInt(3,ordered);
        pstmt.setString(4,description);
        pstmt.setInt(5,status);

        int count = pstmt.executeUpdate();

        System.out.println(count > 0);

        //释放资源
        pstmt.close();
        conn.close();
        //System.out.println(System.getProperty("user.dir"));

    }


    /**
     * 修改数据
     * sql:update brand set brand_name="香飘飘",company_name="香飘飘",ordered=1000,description="销量非常惊人",status=3[where id = 4;
     * @throws Exception
     */


    @Test
    public void testUpdate() throws Exception {
        String brandName = "香飘飘";
        String companyName = "香飘飘";
        int ordered =1000;
        String description = "销量非常惊人";
        int status =3;
        int id = 4;

        Properties prop = new Properties();
        //prop.load(new FileInputStream("jdbc-demo/src/com/itliufu/src/druid.Properties"));
        prop.load(new FileInputStream("src/com/itliufu/druid.Projecties"));
        //4.获取连接池对象
        DataSource dataSource = DruidDataSourceFactory.createDataSource(prop);
        //5.获取数据库连接 Connection
        Connection conn = dataSource.getConnection();

        //定义sql语句
        String sql = "update brand set brand_name=?,company_name=?,ordered=?,description = ?,status=? where id = ?;";

        //获取pstmt对象
        PreparedStatement pstmt = conn.prepareStatement(sql);

        pstmt.setString(1,brandName);
        pstmt.setString(2,companyName);
        pstmt.setInt(3,ordered);
        pstmt.setString(4,description);
        pstmt.setInt(5,status);
        pstmt.setInt(6,id);

        int count = pstmt.executeUpdate();

        System.out.println(count > 0);

        //释放资源
        pstmt.close();
        conn.close();
        //System.out.println(System.getProperty("user.dir"));

    }


    /**
     * 删除数据
     * sql:delete from brand where id = ?;
     * @throws Exception
     */


    @Test
    public void testDelectDataById() throws Exception {
//        String brandName = "香飘飘";
//        String companyName = "香飘飘";
//        int ordered =1000;
//        String description = "销量非常惊人";
//        int status =3;
        int id = 6;

        Properties prop = new Properties();
        //prop.load(new FileInputStream("jdbc-demo/src/com/itliufu/src/druid.Properties"));
        prop.load(new FileInputStream("src/com/itliufu/druid.Projecties"));
        //4.获取连接池对象
        DataSource dataSource = DruidDataSourceFactory.createDataSource(prop);
        //5.获取数据库连接 Connection
        Connection conn = dataSource.getConnection();

        //定义sql语句
        String sql = "delete from brand where id = ?;";

        //获取pstmt对象
        PreparedStatement pstmt = conn.prepareStatement(sql);
        int count = 0;
        //批量删除
        for (int i = 7; i < 11; i++) {
            pstmt.setInt(1,i);
             count += pstmt.executeUpdate();

        }


        System.out.println(count > 0);

        //释放资源
        pstmt.close();
        conn.close();
        //System.out.println(System.getProperty("user.dir"));

    }



}
