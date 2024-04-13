package com.liufu.web;

import com.liufu.mapper.UserMapper;
import com.liufu.pojo.User;
import org.apache.ibatis.io.Resources;
import org.apache.ibatis.session.SqlSession;
import org.apache.ibatis.session.SqlSessionFactory;
import org.apache.ibatis.session.SqlSessionFactoryBuilder;

import javax.servlet.Servlet;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;

@WebServlet(urlPatterns = "/loginServlet")
public class LoginServlet extends HttpServlet {

    @Override
    protected void doGet(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        this.doPost(req, resp);
        //        //1，接收用户名和密码
//        String username = req.getParameter("username");
//        String password = req.getParameter("password");
//
//        //2，调用MyBatis完成查询
//        //2.1 获取SqlSessionFactory对象
//        String resource = "mybatis-config.xml";
//        InputStream inputStream = Resources.getResourceAsStream(resource);
//        SqlSessionFactory sqlSessionFactory = new SqlSessionFactoryBuilder().build(inputStream);
//        //2.2 获取SqlSession对象
//        SqlSession sqlSession = sqlSessionFactory.openSession();
//        //2.3 获取Mapper
//        UserMapper mapper = sqlSession.getMapper(UserMapper.class);
//        //2.4 调用方法
//        User user = mapper.select(username, password);
//        //2.5 释放资源
//        sqlSession.close();
//
//        //获取字符输出流，并设置content type
//        resp.setContentType("test/html;charset=utf-8");
//        PrintWriter writer = resp.getWriter();
//        //3，判断user是否为null
//        if ( user != null){
//            //登录成功
//            writer.write("登录成功");
//        } else {
//            //登录失败
//            writer.write("登录失败");
//        }
//


    }

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        //1，接收用户名和密码
        String username = req.getParameter("username");
        String password = req.getParameter("password");
        User user = new User(username,password);

        //2，调用MyBatis完成查询
        //2.1 获取SqlSessionFactory对象
//        String resource = "mybatis-config.xml";
//        SqlSessionFactory sqlSessionFactory = null;
////        InputStream inputStream = Resources.getResourceAsStream(resource);
////        SqlSessionFactory sqlSessionFactory = new SqlSessionFactoryBuilder().build(inputStream);
//        try (InputStream inputStream = Resources.getResourceAsStream(resource)) {
//            sqlSessionFactory = new SqlSessionFactoryBuilder().build(inputStream);
//            // 使用 sqlSessionFactory 进行后续操作
//        } catch (IOException e) {
//            e.printStackTrace(); // 处理异常或者向上抛出异常
//        }
////        //2.2 获取SqlSession对象
//        SqlSession sqlSession = sqlSessionFactory.openSession();
//        //2.3 获取Mapper
//        UserMapper mapper = sqlSession.getMapper(UserMapper.class);
//        //2.4 调用方法
//        User user = mapper.selectUser(username, password);
//        //2.5 释放资源
//        sqlSession.close();
//
//        //获取字符输出流，并设置content type
        resp.setContentType("test/html;charset=utf-8");
        PrintWriter writer = resp.getWriter();
        //3，判断user是否为null
        if ( user != null){
            //登录成功
            /*writer.write("<!DOCTYPE html>\n" +
                    "<html lang=\"en\">\n" +
                    "<head>\n" +
                    "    <meta charset=\"UTF-8\">\n" +
                    "    <title>Title</title>\n" +
                    "</head>\n" +
                    "<body>\n" +
                    "<h1>登录成功</h1>\n" +
                    "</body>\n" +
                    "</html>");*/
            writer.write("登录成功");
        } else {
            //登录失败
            //writer.write("<html><body><h1>登录失败</h1></body></html>");
            /*writer.write("<!DOCTYPE html>\n" +
                    "<html lang=\"en\">\n" +
                    "<head>\n" +
                    "    <meta charset=\"UTF-8\">\n" +
                    "    <title>Title</title>\n" +
                    "</head>\n" +
                    "<body>\n" +
                    "<h1>登录失败</h1>\n" +
                    "</body>\n" +
                    "</html>");*/
            writer.write("登录成功");
        }

    }
}
