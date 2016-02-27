var dbURL = require("./database.js").getDatabaseURL();
var mongodb = require('mongodb');
var MongoClient = mongodb.MongoClient;
MongoClient.connect(dbURL, function (err, db) {
  if (err) {
    console.log('Unable to connect to database. Error:', err);
  } else {
    db.collection("users").createIndex( { username: 1 }, { unique: true } , function (err, result) {
      if (err) {
        console.log(err);
      } else {
        console.log(result);
      }
      db.close();
    });
  }
});
