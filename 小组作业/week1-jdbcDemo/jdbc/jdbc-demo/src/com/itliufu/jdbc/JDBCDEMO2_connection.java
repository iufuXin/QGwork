package com.itliufu.jdbc;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
import java.sql.Statement;

/**
 * JDBC API详解：connection
 */
public class JDBCDEMO2_connection {

    public static void main(String[] args) throws Exception {
        //1.注册驱动
        //Class.forName("com.mysql.jdbc.Driver");

        //2.获取连接
        String url = "jdbc:mysql://127.0.0.1:3306/dbl1?useSSL=false";
        String username = "root";
        String password = "Lfx520520";
        Connection conn = DriverManager.getConnection(url, username, password);

        //3.定义sql语句
        String sql1 = "update count set money = 3000 where id=1";
        String sql2 = "update count set money = 3000 where id=2";

        //4.获取执行sql的对象 Statement
        Statement stmt = conn.createStatement();

        try {
            //开启事务
            conn.setAutoCommit(false);
            //5.执行sql
            int count1 = stmt.executeUpdate(sql1);
            System.out.println(count1);
            int i = 3/0;
            //5.执行sql
            int count2 = stmt.executeUpdate(sql2);
            System.out.println(count2);
            //提交事务
            conn.commit();
        } catch (Exception e) {
            conn.rollback();
            throw new RuntimeException(e);
        }

        stmt.close();
        conn.close();
    }
}
