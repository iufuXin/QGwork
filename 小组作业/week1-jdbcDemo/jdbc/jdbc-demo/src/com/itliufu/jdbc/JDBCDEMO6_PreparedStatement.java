package com.itliufu.jdbc;

import org.junit.Test;

import java.sql.*;

/**
 * API详解：PreparedStatement
 */
public class JDBCDEMO6_PreparedStatement {

    @Test
    public  void testResultset4() throws Exception {
        //2.获取连接
        String url = "jdbc:mysql://127.0.0.1:3306/dbl1?useSSL=false";
        String username = "root";
        String password = "Lfx520520";
        Connection conn = DriverManager.getConnection(url, username, password);

        String name = "liu";
        String pwd = "123";

        //定义sql语句
        String sql = "select * from tb_user where name = ? and password = ?";

        PreparedStatement pstmt = conn.prepareStatement(sql);

        pstmt.setString(1,name);
        pstmt.setString(2,pwd);

        ResultSet rs = pstmt.executeQuery();


        if ( rs.next()){
            System.out.println("登录成功~~");
        } else {
            System.out.println("登录失败！！");
        }

        rs.close();
        pstmt.close();
        conn.close();

    }

    @Test
    public  void testPraparedStatement() throws Exception {
        //2.获取连接
        String url = "jdbc:mysql://127.0.0.1:3306/dbl1?useSSL=false&useServerPrepStmts=true";
        String username = "root";
        String password = "Lfx520520";
        Connection conn = DriverManager.getConnection(url, username, password);

        String name = "liu";
        String pwd = "123";

        //定义sql语句
        String sql = "select * from tb_user where name = ? and password = ?";

        PreparedStatement pstmt = conn.prepareStatement(sql);

        pstmt.setString(1,name);
        pstmt.setString(2,pwd);

        ResultSet rs = pstmt.executeQuery();


        if ( rs.next()){
            System.out.println("登录成功~~");
        } else {
            System.out.println("登录失败！！");
        }

        rs.close();
        pstmt.close();
        conn.close();

    }

}
