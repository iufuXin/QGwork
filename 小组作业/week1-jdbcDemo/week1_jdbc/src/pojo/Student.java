package pojo;

//创建学生对象
public class Student {
    private int id;//学号
    private String name;//名字
    private String sex;//性别
    private Double score;//绩点

    public Student() {
    }

    public Student(int id, String name, String sex, Double score) {
        this.id = id;
        this.name = name;
        this.sex = sex;
        this.score = score;
    }

    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getSex() {
        return sex;
    }

    public void setSex(String sex) {
        this.sex = sex;
    }

    public Double getScore() {
        return score;
    }

    public void setScore(Double score) {
        this.score = score;
    }

    @Override
    public String toString() {
        return "Student{" +
                "id='" + id + '\'' +
                ", name='" + name + '\'' +
                ", sex='" + sex + '\'' +
                ", score=" + score +
                '}';
    }

}
