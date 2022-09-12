import java.io.Serializable;

public class UserHelperClass implements Serializable {

    String name, number, age, group, gender, willing,latitude,longitude, token;

    public UserHelperClass( ) {
        this.name = null;
        this.number = null;
        this.age = null;
        this.group = null;
        this.gender = null;
        this.willing = null;
        this.latitude = null;
        this.longitude = null;
        this.token = null;
    }

    public UserHelperClass(String name, String number, String age, String group, String gender, String willing, String latitude, String longitude, String token) {
        this.name = name;
        this.number = number;
        this.age = age;
        this.group = group;
        this.gender = gender;
        this.willing = willing;
        this.latitude = latitude;
        this.longitude = longitude;
        this.token = token;
    }

    void display()
    {
        System.out.println(name);
        System.out.println(number);
        System.out.println(age);
        System.out.println(group);
        System.out.println(gender);
        System.out.println(willing);
        System.out.println(latitude);
        System.out.println(longitude);
        System.out.println(token);
    }

    public String getToken() {
        return token;
    }

    public void setToken(String token) {
        this.token = token;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }

    public String getNumber() {
        return number;
    }

    public void setNumber(String number) {
        this.number = number;
    }

    public String getAge() {
        return age;
    }

    public void setAge(String age) {
        this.age = age;
    }

    public String getGroup() {
        return group;
    }

    public void setGroup(String group) {
        this.group = group;
    }

    public String getGender() {
        return gender;
    }

    public void setGender(String gender) {
        this.gender = gender;
    }

    public String getWilling() {
        return willing;
    }

    public void setWilling(String willing) {
        this.willing = willing;
    }

    public String getLatitude() {
        return latitude;
    }

    public void setLatitude(String latitude) {
        this.latitude = latitude;
    }

    public String getLongitude() {
        return longitude;
    }

    public void setLongitude(String longitude) {
        this.longitude = longitude;
    }
}
