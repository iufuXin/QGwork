package com.itliufu.jdbc;

import com.itliufu.pojo.Account;
import org.junit.Test;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.ResultSet;
import java.sql.Statement;
import java.util.ArrayList;
import java.util.List;

/**
 * 用户登录
 */
public class JDBCDEMO5_userLogin {

    @Test
    public  void testResultset4() throws Exception {
        //2.获取连接
        String url = "jdbc:mysql://127.0.0.1:3306/dbl1?useSSL=false";
        String username = "root";
        String password = "Lfx520520";
        Connection conn = DriverManager.getConnection(url, username, password);

        String name = "hskjecd";
        String pwd = "' or '1' = '1";
        String sql = "select * from dbl1.tb_user where name = '"+name+"' and password = '"+pwd+"'" ;

        Statement stmt =  conn.createStatement();

        ResultSet rs = stmt.executeQuery(sql);

        if ( rs.next()){
            System.out.println("登录成功~~");
        } else {
            System.out.println("登录失败！！");
        }

        rs.close();
        stmt.close();
        conn.close();

    }
}
