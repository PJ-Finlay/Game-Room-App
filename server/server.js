var port = 8081;
var express = require('express');
var app = express();

app.all('/', function(req,res){
    res.send("Game Room API Home");
});

//Gets all of the information on a user other than their password
app.get('/users/:username/', function(req,res){
    require("./api_handlers/users.js").getUser(req, res);
});

app.post('/users/:username/:password', function(req,res){
    require("./api_handlers/users.js").postUser(req, res);
});

app.patch('/users/:username/:password/password/:newPassword', function(req,res){
    require("./api_handlers/users.js").updatePassword(req, res);
});

app.patch('/users/:username/:password/name/:name', function(req,res){
    require("./api_handlers/users.js").updateName(req, res);
});

app.patch('/users/:username/:password/email/:email', function(req,res){
    require("./api_handlers/users.js").updateEmail(req, res);
});

app.delete('/users/:username/:password', function(req,res){
    require("./api_handlers/users.js").deleteUser(req, res);
});

app.listen(port, function () {
  console.log('Listening on port: ' + port);
});
