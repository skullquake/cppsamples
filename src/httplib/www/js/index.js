//vue js test
const app=new Vue({
	el:'#main',
	data:{
		foo:'bar',
	},
	methods:{
		fetchAPIData(){ 
		}
	}
})
fetch(
	"http://localhost:1234/hi",
	{
		"method":"GET",
		"headers":{
			"x-foo":"bar",
		}
	}
).then(response=>{
	if(response.ok){
		console.log(response);    
		response.text().then(text=>{
			console.log(text);
		});
	}else{
			console.log("Server returned "+response.status+" : "+response.statusText);
	}
})
