#include"httplib.h"
#include<iostream>
#include<sstream>
int main(int argc,char** argv){
	int port=1234;
	std::cout<<"info: starting"<<std::endl;
	std::cout<<"info: listening on port "<<port<<std::endl;
	httplib::Server svr;
	//--------------------------------------------------------------------------------
	//error handler
	//--------------------------------------------------------------------------------
	svr.set_error_handler([](const auto& req, auto& res) {
		auto fmt = "<p>Error Status: <span style='color:red;'>%d</span></p>";
		char buf[BUFSIZ];
		snprintf(buf, sizeof(buf), fmt, res.status);
		res.set_content(buf, "text/html");
	});
	//--------------------------------------------------------------------------------
	//logger
	//--------------------------------------------------------------------------------
	svr.set_logger([](const httplib::Request&req,const httplib::Response&res){
		std::cout<<req.method<<","<<req.version;
		for(auto it=req.params.begin();it!=req.params.end();++it){
			std::cout<<","<<(it->first)<<":"<<(it->second);
		}
		std::cout<<req.body<<",";
		std::cout<<" -> ";
		std::cout<<res.status;
		std::cout<<res.version;
		std::cout<<std::endl;
		//std::cout<<res.body;
	});
	//--------------------------------------------------------------------------------
	//file server
	//--------------------------------------------------------------------------------
	auto ret=svr.set_mount_point("/","./www");
	if(!ret){
		// todo:handle
	}
	ret = svr.set_mount_point("/public", "./www");
	ret = svr.set_mount_point("/public", "./www1"); // 1st order to search
	ret = svr.set_mount_point("/public", "./www2"); // 2nd order to search
	//ret = svr.remove_mount_point("/");
	//ret = svr.remove_mount_point("/public");
	svr.set_file_extension_and_mimetype_mapping("cc", "text/x-c");
	svr.set_file_extension_and_mimetype_mapping("cpp", "text/x-c");
	svr.set_file_extension_and_mimetype_mapping("hh", "text/x-h");
	//--------------------------------------------------------------------------------
	//service endpoints
	//--------------------------------------------------------------------------------
	svr.Get("/hi",[](const httplib::Request& req,httplib::Response& res){
		std::ostringstream oss;
		std::cout<<"info: /hi"<<std::endl;
		oss<<"lorem"<<std::endl;
		oss<<"ipsum"<<std::endl;
		res.set_content(oss.str(),"text/plain");
	});
	svr.Get(R"(/numbers/(\d+))", [&](const httplib::Request& req, httplib::Response& res) {
		std::cout<<"info: /numbers"<<std::endl;
		auto numbers = req.matches[1];
		res.set_content(numbers, "text/plain");
	});
	svr.Get("/body-header-param", [](const httplib::Request& req, httplib::Response& res) {
		std::cout<<"info: /body-header-param"<<std::endl;
		if (req.has_header("Content-Length")) {
			auto val = req.get_header_value("Content-Length");
		}
		if (req.has_param("key")) {
			auto val = req.get_param_value("key");
		}
		res.set_content(req.body,"text/plain");
	});
	svr.Get("/stop", [&](const httplib::Request& req, httplib::Response& res) {
		std::cout<<"info: /stop"<<std::endl;
		svr.stop();
	});
	svr.listen("localhost",port);
	std::cout<<"info: stopping"<<port<<std::endl;
	return 0;
}
