package com.itliufu.druid;


import com.alibaba.druid.pool.DruidDataSourceFactory;

import javax.sql.DataSource;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.sql.Connection;
import java.sql.DatabaseMetaData;
import java.sql.SQLException;
import java.util.Properties;

/**
 * 数据库连接池
 */


public class DruidDemo {
    public static  void main(String[] args) throws Exception {
        //1.导入jar包

        //2.定义配置文件

        //3.加载配置文件
        Properties prop = new Properties();
        //prop.load(new FileInputStream("jdbc-demo/src/com/itliufu/src/druid.Properties"));
        prop.load(new FileInputStream("jdbc-demo/src/com/itliufu/druid.Projecties"));
        //4.获取连接池对象
        DataSource dataSource = DruidDataSourceFactory.createDataSource(prop);
        //5.获取数据库连接 Connection
        Connection conn = dataSource.getConnection();
        System.out.println(conn);
        System.out.println(System.getProperty("user.dir"));
    }
}
