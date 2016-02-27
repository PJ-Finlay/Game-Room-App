var dbBaseURL = "127.0.0.1";
var dbPort = "27017";
var dbName = "gameroom";

exports.getDatabaseURL = function() {
    return "mongodb://" + dbBaseURL + ":" + dbPort + "/" + dbName;
};