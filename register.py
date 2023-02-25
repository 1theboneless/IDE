import sys
import secrets
from pymongo import MongoClient


def main(username, email, password):
    client = MongoClient("mongodb+srv://eugenelewinston:YZIs8HAnqqDARIIY@registeredusers.9do9nau.mongodb.net/"
                         "?retryWrites=true&w=majority")
    db = client.registered_users
    db_of_users = db.registered_users
    user_email = db_of_users.find_one({"email": email})
    user_username = db_of_users.find_one({"username": username})
    if user_email:
        return print('E-mail already exists')
    elif user_username:
        return print('Username already exists')
    else:
        db_of_users.insert_one(
            {"_id": secrets.token_urlsafe(16), "username": username, "email": email, "password": password})
        return print('Success')


if __name__ == "__main__":
    username = sys.argv[1]
    email = sys.argv[2]
    password = sys.argv[3]
    main(username, email, password)
