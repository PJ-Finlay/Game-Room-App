var dbURL = require("../database.js").getDatabaseURL();

exports.getUser = function(req, res) {
    var assert = require('assert');
    var mongodb = require('mongodb');
    var MongoClient = mongodb.MongoClient;
    MongoClient.connect(dbURL, function (err, db) {
      if (err) {
        console.log('Unable to connect to database. Error:', err);
      } else {
        var params = {username : req.params.username}
        var cursor = db.collection('users').find(params);
        cursor.each(function(err, doc) {
            assert.equal(err, null);
            if (doc != null) {
               delete doc.password;
               res.send(doc);
            } else {
               callback();
            }
        });
      }
    });
};

exports.postUser = function(req, res) {
    var mongodb = require('mongodb');
    var MongoClient = mongodb.MongoClient;
    MongoClient.connect(dbURL, function (err, db) {
      if (err) {
        console.log('Unable to connect to database. Error:', err);
      } else {
        var toAdd = {username: req.params.username, password: req.params.password};
        db.collection('users').insert(toAdd, function (err, result) {
          if (err) {
            console.log(err);
          } else {
            exports.getUser(req, res); //Prints the object
          }
          db.close();
        });
      }
    });
};

exports.deleteUser = function(req, res) {
    var mongodb = require('mongodb');
    var MongoClient = mongodb.MongoClient;
    MongoClient.connect(dbURL, function (err, db) {
      if (err) {
        console.log('Unable to connect to database. Error:', err);
      } else {
        var toAdd = {username: req.params.username, password: req.params.password};
        db.collection('users').remove(toAdd, function (err, result) {
          if (err) {
            console.log(err);
          } else {
            res.send({});
          }
          db.close();
        });
      }
    });
};

exports.updateName = function(req, res) {
    var mongodb = require('mongodb');
    var MongoClient = mongodb.MongoClient;
    MongoClient.connect(dbURL, function (err, db) {
      if (err) {
        console.log('Unable to connect to database. Error:', err);
      } else {
        var toAdd = {name : req.params.name};
        var params = {username : req.params.username , password: req.params.password}
        db.collection('users').update(params, {$set : toAdd} , function (err, result) {
          if (err) {
            console.log(err);
          } else {
            exports.getUser(req, res); //Prints the object
          }
          db.close();
        });
      }
    });
};

exports.updateEmail = function(req, res) {
    var mongodb = require('mongodb');
    var MongoClient = mongodb.MongoClient;
    MongoClient.connect(dbURL, function (err, db) {
      if (err) {
        console.log('Unable to connect to database. Error:', err);
      } else {
        var toAdd = {email : req.params.email};
        var params = {username : req.params.username , password: req.params.password}
        db.collection('users').update(params, {$set : toAdd} , function (err, result) {
          if (err) {
            console.log(err);
          } else {
            exports.getUser(req, res); //Prints the object
          }
          db.close();
        });
      }
    });
};

exports.updatePassword = function(req, res) {
    var mongodb = require('mongodb');
    var MongoClient = mongodb.MongoClient;
    MongoClient.connect(dbURL, function (err, db) {
      if (err) {
        console.log('Unable to connect to database. Error:', err);
      } else {
        var toAdd = {password : req.params.newPassword};
        var params = {username : req.params.username , password: req.params.password}
        db.collection('users').update(params, {$set : toAdd} , function (err, result) {
          if (err) {
            console.log(err);
          } else {
            exports.getUser(req, res); //Prints the object
          }
          db.close();
        });
      }
    });
};
