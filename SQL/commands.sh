sudo apt update
sudo apt install mysql-server -y

sudo service mysql start
sudo service mysql status
sudo mysql

# ------>
sudo mysql online_store < DB.sql 