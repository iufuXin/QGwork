package com.liufu.web;

import com.liufu.mapper.UserMapper;
import com.liufu.pojo.User;
import org.apache.ibatis.io.Resources;
import org.apache.ibatis.session.SqlSession;
import org.apache.ibatis.session.SqlSessionFactory;
import org.apache.ibatis.session.SqlSessionFactoryBuilder;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintWriter;
import java.io.Serial;

@WebServlet("/test2")
public class test2 extends HttpServlet {
    @Serial
    private static final long serialVersionUID = 1L;

    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        System.out.println("到这了");
        String username = request.getParameter("username");
        String password = request.getParameter("password");

        String resource = "mybatis-config.xml";
        try (InputStream inputStream = Resources.getResourceAsStream(resource)) {
            SqlSessionFactory sqlSessionFactory = new SqlSessionFactoryBuilder().build(inputStream);

            try (SqlSession sqlSession = sqlSessionFactory.openSession()) {
                UserMapper mapper = sqlSession.getMapper(UserMapper.class);
                User user = mapper.selectUser(username, password);

                response.setContentType("text/html;charset=utf-8");
                PrintWriter writer = response.getWriter();

                if (user != null) {
                    writer.write("登录成功");
                } else {
                    writer.write("登录失败");
                }
            }
        } catch (IOException e) {
            e.printStackTrace();
            throw new ServletException("数据库配置文件加载失败", e);
        }
    }

    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        doGet(request, response);
    }
}
