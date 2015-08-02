var fsObj=new ActiveXObject("Scripting.FileSystemObject");
var args = WScript.Arguments;
for(var i=0 ; i < args.length ; i++ ){
    var ver = fsObj.GetFileVersion( args.Item(i) );
    WScript.Echo(ver);
}
