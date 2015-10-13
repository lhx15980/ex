package com.ecan.web.student;

import java.io.PrintWriter;
import java.util.Map;

import com.ecan.common.BaseAction;
import com.ecan.common.JacksonUtil;
import com.ecan.common.ResultInfo;
import com.ecan.crm.utils.Constant;
import com.ecan.web.dept.DeptBean;
import com.ecan.web.user.User;
import com.opensymphony.xwork2.ActionContext;

public class StudentAction extends BaseAction {
	
     StudentServiceImpl  serviceImp1 = new StudentServiceImpl();

	public String list() throws Exception {
		//System.out.println("22222");
		return "list";
	}

	public String studentListPageJson() throws Exception {
		String name=request.getParameter("name");
		String age=request.getParameter("age");

		// String search_name=request.getParameter("search_name");
		// String isCheck= request.getParameter("isCheck");
		// Map<String, Object> session = ActionContext.getContext().getSession();
		//User user = (User)session.get(Constant.USER);
		String sql = serviceImp1.getStudentListSql(name,age);
		String strpage = request.getParameter("page");
		String strrows = request.getParameter("rows");
		
		int page = Integer.parseInt((strpage == null || "".equals(strpage))? "1": strpage);
		int rows = Integer.parseInt((strrows == null || "".equals(strrows)) ? "20": strrows);
		
		Map<String, Object> cjList = serviceImp1.getMapForPage(sql, page, rows);
		String result = JacksonUtil.objectConvertToJson(cjList);
		
		response.setContentType("application/json;charset=GBK");
		// 清空缓存的设置
		response.setHeader("pragma", "no-cache");
		response.setHeader("cache-control", "no-cache");
		PrintWriter out = response.getWriter();
		out = response.getWriter();
		out.print(result);
		return this.NONE;
	}
	//新增
     public String saveJson() throws Exception{
        Map<String, Object> session = ActionContext.getContext().getSession();
        User user = (User) session.get(Constant.USER);

    	String id = request.getParameter("id");
		String name = request.getParameter("name");
		String age = request.getParameter("age");
		
		StudentBean studentBean = new StudentBean();
		
		studentBean.setId(id);
		studentBean.setName(name);
		studentBean.setAge(age);
		//studentBean.setPhone(id);
		//studentBean.setPerson(person);
		//deptBean.setOrg_code(Integer.parseInt(org_code));
		
		ResultInfo resultInfo = new ResultInfo();
		resultInfo = serviceImp1.saveStudent(studentBean);
		
		String result = JacksonUtil.objectConvertToJson(resultInfo);
		PrintWriter out = response.getWriter();
		response.setHeader("pragma", "no-cache");
		response.setHeader("cache-control", "no-cache");
		out = response.getWriter();
		out.print(result);
		return this.NONE;
	}
     //修改
     public String editStudent() throws Exception{
    	 Map<String, Object> session = ActionContext.getContext().getSession();
         User user = (User) session.get(Constant.USER);

 	    String name = request.getParameter("name");
 		String age = request.getParameter("age");
 		String id = request.getParameter("id");
 		//String person = request.getParameter("person");
 		//String org_name = request.getParameter("org_name");
 		//String id = request.getParameter("id");
 		
 		StudentBean studentBean = serviceImp1.getStudentById(id);
 		
 	    studentBean.setName(name);
 		studentBean.setAge(age);
 		//studentBean.setId(id);
 		//studentBean.setPerson(person);
 		//deptBean.setOrg_code(Integer.parseInt(org_code));
 		
 		ResultInfo resultInfo = new ResultInfo();
 	    resultInfo = serviceImp1.modifyStudent(studentBean);
        String result = JacksonUtil.objectConvertToJson(resultInfo);				
 		//response.setContentType("application/json;charset=GBK");
 		// 清空缓存的设置
 		response.setHeader("pragma", "no-cache");
 		response.setHeader("cache-control", "no-cache");
 		PrintWriter out = response.getWriter();
 		out = response.getWriter();
 		out.println(result);
 		return this.NONE;		
 	} 
    //删除
     public String deleteStudent() throws Exception{
		 
 	 	String id= request.getParameter("id");
 		ResultInfo resultInfo = serviceImp1.delStudentById(id);
 		String result = JacksonUtil.objectConvertToJson(resultInfo);
 		PrintWriter out = response.getWriter();
 		out = response.getWriter();
 		out.print(result);
 		
 		response.setHeader("pragma", "no-cache");
 		response.setHeader("cache-control", "no-cache");
 		return this.NONE;
 	}
}
