const salt = "GameRoomSalt";


exports.hashString = function(string){
    string += salt;
    const crypto = require('crypto');
    const hash = crypto.createHash('sha256');
    hash.update(string);
    return hash.digest('hex');
};