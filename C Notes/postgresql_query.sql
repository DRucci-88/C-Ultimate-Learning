CREATE DATABASE cranium;
CREATE SCHEMA IF NOT EXISTS training;
SET search_path=training;

CREATE SEQUENCE training.products_id_seq;
CREATE TABLE IF NOT EXISTS training.products (
  productID    INT   NOT NULL DEFAULT nextval('training.products_id_seq'),
  productCode  CHAR(3)       NOT NULL DEFAULT '',
  name         VARCHAR(30),
  quantity     INT   NOT NULL DEFAULT 0,
  price        DECIMAL(7,2)  NOT NULL DEFAULT 99999.99,
  PRIMARY KEY  (productID)
);
ALTER SEQUENCE training.products_id_seq OWNED BY training.products.productID;

INSERT INTO training.products (productID, productCode, name, quantity, price) VALUES 
(1001, 'PEN', 'Pen Red', 5000, 1.23),
(1002, 'PEN', 'Pen Blue',  8000, 1.25),
(1003, 'PEN', 'Pen Black', 2000, 1.25),
(1004, 'PEC', 'Pencil 2B', 10000, 0.48),
(1005, 'PEC', 'Pencil 2H', 8000, 0.49),
(1006, 'PEC', NULL, 0, 0);

SELECT name, price FROM training.products WHERE name LIKE 'PENCIL%';
SELECT name, price FROM training.products WHERE name LIKE 'Pencil%';
SELECT * FROM training.products WHERE quantity >= 5000 AND price < 1.24 AND name LIKE 'Pen %';
SELECT * FROM training.products WHERE NOT (quantity >= 5000 AND name LIKE 'Pen %');
SELECT * FROM training.products WHERE name IN ('Pen Red', 'Pen Black');
SELECT * FROM training.products WHERE (price BETWEEN 1.0 AND 2.0) AND (quantity BETWEEN 1000 AND 2000);

SELECT * FROM training.products WHERE name IS NULL;
SELECT * FROM training.products WHERE name = NULL; -> Wrong

SELECT * FROM training.products WHERE name LIKE 'Pen %' ORDER BY price DESC, quantity;

AS - Alias:
SELECT productID AS ID, productCode AS Code, name AS Description, price AS unitPrice FROM products ORDER BY ID;

SELECT CONCAT(productCode, ' - ', name) AS productDescription, price FROM products;

SELECT DISTINCT price AS distinctPrice FROM products;
SELECT DISTINCT price, name FROM products;

SELECT productCode, COUNT(1) AS total FROM products GROUP BY productCode ORDER BY total DESC;

SELECT productCode, MAX(price), MIN(price), AVG(price), SUM(quantity) FROM products GROUP BY productCode;

SELECT productCode, COUNT(1) AS total FROM products GROUP BY productCode HAVING COUNT(1) >=3;
SELECT productCode, COUNT(1) AS total FROM products WHERE COUNT(1) >=3 GROUP BY productCode; -> Wrong


CREATE TABLE training.suppliers (
  supplierID  SERIAL, 
  name        VARCHAR(30)   NOT NULL DEFAULT '', 
  phone       CHAR(8)       NOT NULL DEFAULT '',
  PRIMARY KEY (supplierID)
);

INSERT INTO suppliers(supplierID, name, phone) VALUES 
(501, 'ABC Traders', '88881111'), 
(502, 'XYZ Company', '88882222'), 
(503, 'QQ Corp', '88883333');

ALTER TABLE products ADD COLUMN supplierID INT;
UPDATE products SET supplierID = 501;
ALTER TABLE products ALTER COLUMN supplierID SET NOT NULL;
ALTER TABLE products ADD CONSTRAINT fk_products_supplierid_suppliers FOREIGN KEY (supplierID) REFERENCES suppliers (supplierID);
UPDATE products SET supplierID = 502 WHERE productID  = 1004;

SELECT products.name, price, suppliers.name 
FROM products 
JOIN suppliers ON products.supplierID = suppliers.supplierID
WHERE price < 0.6;

SELECT products.name, price, suppliers.name 
FROM products, suppliers 
WHERE products.supplierID = suppliers.supplierID
AND price < 0.6;

SELECT p.name AS productName, p.price, s.name AS supplierName 
FROM products AS p 
JOIN suppliers AS s ON p.supplierID = s.supplierID
WHERE p.price < 0.6;

CREATE TABLE products_suppliers (
  productID   INT   NOT NULL,
  supplierID  INT   NOT NULL,
  PRIMARY KEY (productID, supplierID),
  FOREIGN KEY (productID)  REFERENCES products  (productID),
  FOREIGN KEY (supplierID) REFERENCES suppliers (supplierID)
);

INSERT INTO products_suppliers (productID, supplierID) VALUES 
(1001, 501), 
(1002, 501),
(1003, 501), 
(1004, 502);

ALTER TABLE products DROP CONSTRAINT fk_products_supplierid_suppliers;
ALTER TABLE products DROP supplierID;

SELECT p.name AS productName, s.name AS supplierName
FROM products_suppliers AS ps 
JOIN products AS p ON ps.productID = p.productID
JOIN suppliers AS s ON ps.supplierID = s.supplierID
WHERE p.name = 'Pencil 2B';

SELECT p.name AS productName, s.name AS supplierName
FROM products AS p, products_suppliers AS ps, suppliers AS s
WHERE p.productID = ps.productID
AND ps.supplierID = s.supplierID
AND s.name = 'ABC Traders';

SELECT su.supplierID, su.name 
FROM suppliers su 
WHERE EXISTS (SELECT 1 FROM products_suppliers ps WHERE ps.supplierID = su.supplierID);

/*
CREATE TABLE product_details (
  productID  SERIAL,
  comment    TEXT  NULL,
  PRIMARY KEY (productID),
  FOREIGN KEY (productID) REFERENCES products (productID)
);
*/

//SELECT with Subquery:
1. WHERE clause
SELECT suppliers.name 
FROM suppliers
WHERE suppliers.supplierID NOT IN (SELECT DISTINCT supplierID from products_suppliers);

2. SELECT clause
SELECT p1.productCode, p1.name,  
  (SELECT MIN (quantity)  
   FROM products p2  
   WHERE p2.productCode = p1.productCode)
FROM products p1;

3. FROM clause
SELECT products.productCode, products.price, products.quantity  
FROM (SELECT productCode, AVG(price) AS price, SUM(quantity) AS quantity FROM products GROUP BY productCode) AS products 
WHERE products.price < 1;


CREATE TABLE t1 (
  id      SERIAL PRIMARY KEY,
  description  VARCHAR(30)
);

CREATE TABLE t2 (
  id      SERIAL PRIMARY KEY,
  description  VARCHAR(30)
);

INSERT INTO t1 (id, description) VALUES
(1, 'ID 1 in t1'),
(2, 'ID 2 in t1'),
(3, 'ID 3 in t1');

INSERT INTO t2 (id, description) VALUES
(2, 'ID 2 in t2'),
(3, 'ID 3 in t2'),
(4, 'ID 4 in t2');


SELECT * FROM t1 INNER JOIN t2; -> Error
SELECT * FROM t1, t2;
SELECT * FROM t1 INNER JOIN t2 ON t1.id = t2.id;

SELECT t1.id,t1.description,t2.id,t2.description FROM t1 LEFT JOIN t2 ON t1.id = t2.id;
SELECT t1.id,t1.description,t2.id,t2.description FROM t1 RIGHT JOIN t2 ON t1.id = t2.id;


SET AUTOCOMMIT = OFF;
UPDATE t1 SET description = 'ID 2 in t1' WHERE id = 1;
UPDATE t1 SET description = 'ID 1 in t1' WHERE id = 2;
ROLLBACK;
