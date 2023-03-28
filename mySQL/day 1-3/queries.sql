--- 1 ---
-- Which Products have been Ordered by a Customer
-- customerID must be any number, witch exists in table
select p.productID, p.name, p.price, o.count from orders as ord
inner Join orderLines as o on o.orderID = ord.orderID
inner Join products as p on p.productID = o.productID
where customerID = 1;


--- 2 ---
-- What date/time was a particular Order dispatched
-- orderID must be number, witch exists in table
select time, orderID from orders where orderID = 25;


--- 3 ---
-- How many open Orders do we have in the system
-- Get products that not deliveried for customer
select p.productID, p.name, p.price, o.count, ord.time from orders as ord
inner join orderLines as o on o.orderID = ord.orderID
inner join products as p on p.productID = o.productID
where o.isDev = 0 and customerID = 2;
-- Get count not deliveried orders
select count(orderID) as count from orderLines where isDev = 0;


--- 4 ---
-- How many of a certain Product do we have in stock
select count(*) from products where count <> 0;


--- 5 ---
-- Which Supplier supplies a particular Product
select p.productID, p.name, s.supplierID, s.name from products as p
inner join suppliers as s on s.supplierID = p.supplierID where productID = 1;


--- 6 ---
-- What is the Total Order cost for a certain Order
-- 1 must be any number witch exists in orders table orderID
SELECT sum(orderLines.count * products.price) AS cost FROM orderLines
JOIN products ON orderLines.productID = products.productID WHERE orderID = "1";