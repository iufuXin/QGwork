package org.example;

import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.io.PrintWriter;

@WebServlet("/getData")
public class SimulationData extends HttpServlet {
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws IOException {
        // 模拟一些数据
        String name = "liufu xin";
        int age = 30;
        String email = "liufu@example.com";

        // 设置响应内容类型为 JSON
        response.setContentType("application/json");

        // 创建 JSON 字符串
        String json = "{\"name\": \"" + name + "\", \"age\": " + age + ", \"email\": \"" + email + "\"}";

        // 获取PrintWriter对象，用于向响应输出数据
        PrintWriter out = response.getWriter();
        // 将JSON数据写入响应
        out.print(json);
        // 刷新缓冲区，确保数据被发送到客户端
        out.flush();
    }

    @Override
    protected void doPost(HttpServletRequest req, HttpServletResponse resp) throws ServletException, IOException {
        this.doGet(req, resp);
    }
}
