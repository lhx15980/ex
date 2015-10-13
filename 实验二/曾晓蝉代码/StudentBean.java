package com.ecan.web.student;

public class StudentBean implements java.io.Serializable  {

	public StudentBean() {
		super();
		// TODO Auto-generated constructor stub
	}
	private String id;
	private String name;
	private String age;
	//private Integer sort;
	//private String person;
	//private String phone;
	//private Integer org_code;
	public String getId() {
		return id;
	}
	public void setId(String id) {
		this.id = id;
	}
	public String getName() {
		return name;
	}
	public void setName(String name) {
		this.name = name;
	}
	public String getAge() {
		return age;
	}
	public void setAge(String age) {
		this.age = age;
	}	
}
