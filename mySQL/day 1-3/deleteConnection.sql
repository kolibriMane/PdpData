-- Delete from table where exists primary key
-- Automaticaly delete every row where exists customer ID
CREATE TRIGGER deleteConnections AFTER DELETE ON orders
FOR EACH ROW
DELETE FROM orderLines WHERE orderID = old.orderID;