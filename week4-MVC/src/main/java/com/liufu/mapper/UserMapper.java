package com.liufu.mapper;

import com.liufu.pojo.User;
import org.apache.ibatis.annotations.Param;
import org.apache.ibatis.annotations.Select;

public interface UserMapper {
    /**
     * 根据用户名和密码查询用户对象
     * @param username
     * @param password
     * @return
     */
    @Select("select * from dbl1.tb_user where username = #{username} and password = #{password}")
    User selectUser(@Param("username") String username, @Param("password")String password);
    //User select( String username,String password);
}
