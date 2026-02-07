-- CREATE DATABASE online_store;
-- USE online_store;
CREATE TABLE IF NOT EXISTS users(
    user_id INT PRIMARY KEY AUTO_INCREMENT,
    name VARCHAR(100) NOT NULL,
    email VARCHAR(50) UNIQUE NOT NULL,
    phone VARCHAR(13),
    created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP
);

CREATE TABLE IF NOT EXISTS categories (
    category_id INT PRIMARY KEY AUTO_INCREMENT,
    category_name VARCHAR(100) UNIQUE NOT NULL
);

CREATE TABLE IF NOT EXISTS products(
    product_id INT AUTO_INCREMENT PRIMARY KEY,
    product_name VARCHAR(100) NOT NULL,
    price DECIMAL(10,2) CHECK (price > 0),
    stock INT DEFAULT 0,
    category_id INT,
    FOREIGN KEY (category_id) REFERENCES categories(category_id)
);

CREATE TABLE IF NOT EXISTS orders (
    order_id INT PRIMARY KEY AUTO_INCREMENT,
    user_id INT,
    order_date TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    status VARCHAR(20) DEFAULT 'PLACED',
    FOREIGN KEY (user_id) REFERENCES users(user_id)
);

CREATE TABLE IF NOT EXISTS order_items (
    order_item_id INT PRIMARY KEY AUTO_INCREMENT,
    order_id INT,
    product_id INT,
    quantity INT CHECK (quantity > 0),
    FOREIGN KEY (order_id) REFERENCES orders(order_id),
    FOREIGN KEY (product_id) REFERENCES products(product_id)
);

INSERT INTO users (name, email, phone) VALUES
('Amit Sharma', 'amit@gmail.com', '9123456780'),
('Rohit Verma', 'rohit@gmail.com', '9234567891'),
('Sneha Patil', 'sneha@gmail.com', '9345678912'),
('Priya Singh', 'priya@gmail.com', '9456789123');

INSERT INTO categories (category_name) VALUES
('Clothing'), ('Home Appliances'), ('Sports'), ('Stationery'), ('Mobiles');

INSERT INTO products (product_name, price, stock, category_id) VALUES
('Smartphone', 25000, 20, 5),
('T-Shirt', 799, 100, 1),
('Jeans', 1999, 60, 1),
('Washing Machine', 32000, 5, 2),
('Refrigerator', 45000, 4, 2);

INSERT INTO orders (user_id, status) VALUES
(1, 'PLACED'),
(2, 'SHIPPED'),
(3, 'DELIVERED');

INSERT INTO order_items (order_id, product_id, quantity) VALUES
(1, 1, 1),
(1, 2, 2),
(2, 3, 1),
(3, 4, 1);
SELECT o.order_id, p.product_name, oi.quantity,u.name AS customer_name
FROM orders o
JOIN users u ON o.user_id =u.user_id
JOIN order_items oi ON oi.order_id=o.order_id
JOIN products p ON p.product_id=oi.product_id
