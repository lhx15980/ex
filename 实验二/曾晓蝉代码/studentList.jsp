<%@ page language="java" import="java.util.*" pageEncoding="UTF-8"%>
<%
String path = request.getContextPath();
String basePath = request.getScheme()+"://"+request.getServerName()+":"+request.getServerPort()+path+"/";
%>

<!DOCTYPE html>
<html>
  <head>
    <jsp:include page="/jsp/meta.jsp" />
    <title>TEST</title>
    <script type="text/javascript">
        var url;
        var type;
   //新增学生信息
      function addStudent() { 
         //使用新增面板的ID  dlg,fm
            $("#dlg").dialog("open").dialog('setTitle', '新增学生'); 
            $("#fm").form("clear");
           //var name = $("#name").combobox('getValue');
            url = "<%=path%>/StudentAction!saveJson.action";
           // document.getElementById("hidtype").value="submit";
        }
   //修改学生信息    
       function editStudent() {
           
            var row = $("#dg").datagrid("getSelected");
            if (row) {
                $("#dlg").dialog("open").dialog('setTitle', '修改学生信息');
                $("#fm").form("load", row);
                // var name = $("#name").combobox('getValue');
                url = "<%=path%>/StudentAction!editStudent.action";
                
            }
        }
 //针对无论是新增还是修改 都要进行保存   	
      function saveStudent() {
              var row = $("#dg").datagrid("getSelected");
              $("#fm").form("submit", {              
                url:url,
                onsubmit: function () {
                    return $(this).form("validate");
                },
                success: function (result) {
                	  var result = eval('('+result+')');
                	    if (result.flag) {
                        $.messager.alert("提示信息", "操作成功");
                        $("#dlg").dialog("close");
                        $("#dg").datagrid("load");
                    }
                    else {
                        $.messager.alert("提示信息", "操作失败");
                    }
                }
            });
        }
     //删除学生
        function delStudent(){
         var row = $('#dg').datagrid('getSelected');
        if (row){
          var id=row.id;
          $.messager.confirm('确定','你是否确定删除这个学生吗？',function(r){
                if (r){
                    $.post('<%=path%>/StudentAction!deleteStudent.action',{id:id},function(result){
                        if (result.flag){
                            $('#dg').datagrid('reload');    // reload the user data
                        } else {
                            $.messager.show({    // show error message
                                title: '错误',
                                msg: result.message
                            });
                        }
                    },'json');
                }
            });
    	}
	}
 //查询
      function searchStudent(){
       //var cardId=$("#cardId").val();
       var name=$("#name").val();
       var age=$("#age").val();
       $('#dg').datagrid({
         queryParams: {   
         	name:name,   
         	age:age
          }
        });
   	} 
   	//对查询条件 清空 以便下次再查询 
      function clearStudent(){
        $("#f-query").form('clear');
   	}  
    </script> 
 </head>
  
<body class = "easyui-layout">
<!--  查询面板-->
   <div data-options="region:'north',border:false" style="height:50px;">
		<form id="f-query" method="post">
            <table cellpadding="5">
                <tr>
                    <td>学生姓名:</td>
		            <td> <input class = "easyui-textbox" type="text" id="name" name="name"></input></td>
                    <td>学生年龄:</td>
                    <td><input class="easyui-textbox" type="text" id="age" name="age"></input></td>
                    <td>
                    <a href="javascript:void(0)" class="easyui-linkbutton" 
                    iconCls="icon-search"  id="f-search-btn" onclick="searchStudent()">查询</a>&nbsp;&nbsp;                  
                    <!--  <input type="button" onclick="search()" value="查询" />&nbsp;&nbsp;-->
                    <a href="javascript:void(0)" class="easyui-linkbutton" 
                    id="f-clear-btn" onclick="clearStudent()">&nbsp;&nbsp;清空&nbsp;&nbsp;</a>
                    </td> 
                </tr>
            </table>    
          
        </form>
	</div>
<!-- 查询面板下方显示面板 -->	
	<div data-options="region:'center',border:false">
		<table id="dg" class="easyui-datagrid" title="学生信息管理"
		pagesize="20" pageList="[10,15,20]"  
    	pagination="false"
		url= "<%=path%>/StudentAction!studentListPageJson.action"
			data-options="
		   		   method:'post',
		   		   singleSelect:false,
		   		   fit:true,
		   		    fitColumns:true,
		   		  rownumbers:true,
		   		    toolbar:'#toolbar',
		   		    pagination:true"	
		   		   >	   		   
	          <thead>
	          <tr>
				    <th data-options="field:'id',checkbox:true" width="50">e</th>
					<th data-options="field:'name'" width="50">学生姓名</th>
					<th data-options="field:'age'" width="50">学生年龄</th>	
				</tr>
			</thead>
		</table>
			</div>
	<!-- 有哪些按钮 -->
	<div id="toolbar">
			<a href="javascript:void(0)" class="easyui-linkbutton"
			iconCls="icon-add" plain="true" id="tool-add-btn"
			   onclick="addStudent()">增加</a>			 
			<a href="javascript:void(0)" class="easyui-linkbutton"
			 iconCls="icon-edit" plain="true" id="tool-edit-btn"
			   onclick="editStudent()">修改</a>
			<a href="javascript:void(0)" class="easyui-linkbutton" 
			iconCls="icon-remove" plain="true" id="tool-remove-btn"
			   onclick="delStudent()">移除</a>		  					
	</div>

<!-- 新增面板  也是 修改面板  主要就是  通过Id  dlg  fm 进行控制 -->
	<div id="dlg" class="easyui-dialog" iconCls="icon-save"
		style="width: 500px; height: 400px; padding: 5px;"
        closed="true"
		buttons="#dlg-buttons">
		<div data-options="region:'center'" style="padding:10px;">
		<div class="ftitle">信息编辑</div>
		<form id="fm" method="post">
			 <table cellpadding="5">
			      <tr>
		              <td> <input type="hidden" name="id" id="id" /></td>
		               </tr>
		               <tr>
		                    <td>学生姓名：</td>
		                    <td><input class="easyui-textbox" type="text" name="name" id="name" data-options="required:true"/>
		                    </td>
		                   </tr>
		                   
		                  <tr>
		                   <td>学生年龄：</td>
                         <td><input class="easyui-textbox" type="text" name="age" id="age" data-options="required:true"/>
                         </td>
		                </tr>		                   
	            </table>
			 <input type="hidden" name="action" id="hidtype" /> 
	  </form>
	</div>
</div>
	<div id="dlg-buttons">
		<a href="javascript:void(0)" id="add-save-btn" class="easyui-linkbutton"
			onclick="saveStudent()" iconcls="icon-ok">保存</a>
		<a href="javascript:void(0)"id="add-close-btn" class="easyui-linkbutton"
		   onclick="javascript:$('#dlg').dialog('close')"  iconcls="icon-cancel">取消</a>	
	  </div>
	  	
  </body>
</html>
