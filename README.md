# School-management
School Management System using C++ &amp; MySQL
# 🎓 Student Record Management System

A simple C++ console-based application that connects to a MySQL database to manage student records. This project demonstrates the integration of C++ with MySQL using the MySQL C API.

## 📌 Features

- Connects to MySQL database (`school`)
- Inserts student data into a `student` table
- Accepts inputs for:
  - College ID
  - Name
  - Birth Date (YYYY-MM-DD)
  - Grade
- Loop-based input for adding multiple records
- Basic error handling and feedback

## 🛠 Tech Stack

- **C++**
- **MySQL**
- **MySQL C API** (`mysql.h`, `mysqld_error.h`)

## 🗃 Database Schema

Before running the project, create the following MySQL database and table:

```sql
CREATE DATABASE school;

USE school;

CREATE TABLE student (
  College_ID INT PRIMARY KEY,
  Name VARCHAR(50),
  BirthDate DATE,
  Grade FLOAT
);
