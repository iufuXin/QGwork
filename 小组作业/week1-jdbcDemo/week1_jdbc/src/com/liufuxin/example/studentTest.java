package com.liufuxin.example;

import java.sql.Connection;

public class studentTest {
    public static void main(String[] args) throws Exception{
        //获取连接
        Connection conn = work.connectionDatabase();
        //用户的选择
        String choose = new String();
        //增删查改操作
        while (true) {
            work.show();
            //读入用户选择
            choose = work.sc.next();
            //work.sc.next();
            if ( choose.equals("A")){
                work.DataAdd(conn);
            } else if (choose.equals("B")) {
                work.queryAllData(conn);
            } else if (choose.equals("C")) {
                work.UpdateData(conn);
            } else if (choose.equals("D")) {
                work.delectData(conn);
            } else if (choose.equals("E")) {
                break;
            }
        }
        //释放资源
        conn.close();
    }
}
