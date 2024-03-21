package com.itliufu.jdbc;

import org.junit.Test;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
import java.sql.Statement;

/**
 * JDBC API详解：Statement
 */
public class JDBCDEMO3_statement {
    /**
     * 执行DML语句
     * @throws Exception
     */


    @Test
    public  void testDml() throws Exception {
        //1.注册驱动
        //Class.forName("com.mysql.jdbc.Driver");

        //2.获取连接
        String url = "jdbc:mysql://127.0.0.1:3306/dbl1?useSSL=false";
        String username = "root";
        String password = "Lfx520520";
        Connection conn = DriverManager.getConnection(url, username, password);

        //3.定义sql语句
        //String sql = "update user set money = 3000 where id=5";

        String sql = "drop database `db2`";

        //4.获取执行sql的对象 Statement
        Statement stmt = conn.createStatement();

        //5.执行sql
        int count = stmt.executeUpdate(sql);

        //System.out.println(count);
        if ( count > 0){
            System.out.println("修改成功~~");
        }else {
            System.out.println("修改失败~~");
        }
        stmt.close();
        conn.close();


    }
}
