public class no 
{
    public static void main(String[] args) 
    {
        UserHelperClass u = new UserHelperClass("name", "number", "age", "group", "gender", "willing", "latitude", "longitude", "token");
        String a = u.age;
        System.out.println(a);
        u.display();
    }
}
