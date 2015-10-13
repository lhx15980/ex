package com.ecan.web.student;


import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

import com.ecan.common.Global;
import com.ecan.common.JdbcDBUtil;
import com.ecan.common.JdbcUtil;
import com.ecan.common.ResultInfo;
import com.ecan.web.user.User;
import com.opensymphony.xwork2.ActionContext;


public class StudentServiceImpl {
	public List<StudentBean> getStudnetList(String pageSQL) {
		return JdbcDBUtil.getListForBean(pageSQL, StudentBean.class);
	}
	
 public String getStudentListSql(String name,String age){
	// Map<String, Object> session = ActionContext.getContext().getSession();
	 //User user = new User();
	// user=(User) session.get(Constant.USER);
		StringBuffer sql = new StringBuffer();
		sql.append(" select id,name,age");
		sql.append(" from t_student a ");
		//sql.append(" where 1=1");
		if(name!=null&&!"".equals(name)){
		sql.append(" where a.name like '%").append(""+name+"").append("%'");
		
		}
		if(age!=null&&!"".equals(age)){
			sql.append(" where  a.age = '").append(""+age+"").append("'");
			}
		return sql.toString();
		
  }

  public Map<String, Object> getMapForPage(String sql, int page, int rows) {
	Map<String, Object> jsonMap = new HashMap<String, Object>();
	String countSQL = JdbcUtil.createCountSQL(sql);
	int rsCount = JdbcUtil.getCount(countSQL);
	int firstRow = rows * (page - 1);
	String pageSQL = JdbcUtil.createPageSQLForOrder(sql, "a.id", firstRow, rows);
    List<Map<String, Object>> deptList = JdbcDBUtil.getListForMap(pageSQL);
	jsonMap.put("total", rsCount);
	jsonMap.put("rows", deptList);
	
	return jsonMap;
 }
//新增学生
  public ResultInfo saveStudent(StudentBean bean) {
	List<String> sqlList = new ArrayList<String>();
	String id = Global.createUUID();
	StringBuilder studentsql = new StringBuilder();
	studentsql.append("insert into t_student(");
	studentsql.append("id,name,age");
	studentsql.append(") values(");
	studentsql.append("'" + id + "',");
	studentsql.append("'" + bean.getName() + "',");
	studentsql.append("'" + bean.getAge()+"')");
	//deptsql.append("'" + bean.getPerson() + "',");
	//deptsql.append("'" + bean.getPhone()+ "',");
	//deptsql.append("'" + org_name + "')");
	sqlList.add(studentsql.toString());
	System.out.println(studentsql);
	ResultInfo resultInfo = new ResultInfo();
	try {
		boolean flag = JdbcUtil.transactionUpdate(sqlList
				.toArray(new String[sqlList.size()]), sqlList.size());
		resultInfo.setFlag(true);
	} catch (Exception e) {
		e.printStackTrace();
		resultInfo.setFlag(false);
		resultInfo.setMessage(e.getMessage());
	}
	return resultInfo;
 }
//修改学生
  public ResultInfo modifyStudent(StudentBean bean) {
	List<String> sqlList = new ArrayList<String>();
	StringBuilder sql = new StringBuilder();
	String id = bean.getId();
	sql.append("Update t_student set ");
	sql.append("age = '" + bean.getAge() + "',");
	sql.append("name = '" + bean.getName() + "'");
	//sql.append("person = '" + bean.getPerson()+ "',");
	//sql.append("phone = '" + bean.getPhone() + "',");
	//sql.append("org_code = '" + org_name +"'");
	sql.append(" where id = '" + id + "'");

	sqlList.add(sql.toString());
	System.out.println(sql);
	
	ResultInfo resultInfo = new ResultInfo();
	try {
		boolean flag = JdbcUtil.transactionUpdate(sqlList
				.toArray(new String[sqlList.size()]), sqlList.size());
		resultInfo.setFlag(true);
	} catch (Exception e) {
		e.printStackTrace();
		resultInfo.setFlag(false);
		resultInfo.setMessage(e.getMessage());
	}
	
	return resultInfo;
 }
  //修改时获得的Id号
  public StudentBean getStudentById(String id) {
		StudentBean StudentBean = new StudentBean();
		String sql = "Select * from t_student where id = '" + id + "'";
		StudentBean = JdbcDBUtil.getObjectForBean(sql, StudentBean.class);
		return StudentBean;
	 }
  //删除时获得的Id 删除所对应的行
 public ResultInfo delStudentById(String id) {
	ResultInfo resultInfo = new ResultInfo();
	String sql = "Delete From t_student where id = '" + id + "'";
	List<String> sqlList = new ArrayList<String>();
	try {
		sqlList.add(sql);	
		boolean flag = JdbcUtil.transactionUpdate(sqlList
				.toArray(new String[sqlList.size()]));
		resultInfo.setFlag(true);
	} catch (Exception e) {
		e.printStackTrace();
		resultInfo.setFlag(false);
		resultInfo.setMessage(e.getMessage());
	}
	
	return resultInfo;
 }
}
