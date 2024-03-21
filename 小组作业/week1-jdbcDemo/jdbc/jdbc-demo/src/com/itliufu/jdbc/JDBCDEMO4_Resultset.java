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
 * JDBC API详解：Statement
 */
public class JDBCDEMO4_Resultset {
    /**
     * 执行DQL查询语句
     * @throws Exception
     */


    @Test
    public  void testResultset2() throws Exception {
        //1.注册驱动
        //Class.forName("com.mysql.jdbc.Driver");

        //2.获取连接
        String url = "jdbc:mysql://127.0.0.1:3306/dbl1?useSSL=false";
        String username = "root";
        String password = "Lfx520520";
        Connection conn = DriverManager.getConnection(url, username, password);

        //3.定义sql语句
        //String sql = "update user set money = 3000 where id=5";

        String sql = "select * from dbl1.count";

        //4.获取执行sql的对象 Statement
        Statement stmt = conn.createStatement();

        //5.执行sql

        ResultSet rs = stmt.executeQuery(sql);

        List<Account> list = new ArrayList<>();

        while (rs.next()){
            Account account = new Account();
            int id = rs.getInt("id");
            String name = rs.getString("name");
            int money = rs.getInt("money");

            account.setId(id);
            account.setName(name);
            account.setMoney(money);

            list.add(account);

        }

        System.out.println(list);

        rs.close();
        stmt.close();
        conn.close();

    }
}
