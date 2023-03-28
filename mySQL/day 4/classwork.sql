drop procedure myProc;
--- Query for join with procedure ---
--- Delete procedure if exists yet ---
drop procedure myProc;
delimiter //

CREATE PROCEDURE myProc(in one integer, in two integer)
BEGIN
SELECT * FROM customers INNER JOIN orders using(customerID)
INNER JOIN orderLines using(orderID)
INNER JOIN products using(productID) WHERE customerID = one and productID = two;
END//
delimiter ;

call myProc(1, 2);


--- Trigger to update delivery time when updating isDev column ---
--- Delete trigger if exists yet ---
drop trigger myTrigger;
delimiter //

CREATE TRIGGER myTrigger AFTER UPDATE ON orderLines
FOR EACH ROW
BEGIN
IF new.isDev = 1 THEN
update orders set orders.delTime = NOW() where orders.orderID = new.orderID;
END IF;
END //

delimiter ;