-- Table: Customer

-- +-------------+---------+
-- | Column Name | Type    |
-- +-------------+---------+
-- | id          | int     |
-- | name        | varchar |
-- | referee_id  | int     |
-- +-------------+---------+
-- In SQL, id is the primary key column for this table.
-- Each row of this table indicates the id of a customer, their name, and the id of the customer who referred them.
--  

-- Find the names of the customer that are not referred by the customer with id = 2.

-- Return the result table in any order.

-- The result format is in the following example.

--  

-- Example 1:

-- Input: 
-- Customer table:
-- +----+------+------------+
-- | id | name | referee_id |
-- +----+------+------------+
-- | 1  | Will | null       |
-- | 2  | Jane | null       |
-- | 3  | Alex | 2          |
-- | 4  | Bill | null       |
-- | 5  | Zack | 1          |
-- | 6  | Mark | 2          |
-- +----+------+------------+
-- Output: 
-- +------+
-- | name |
-- +------+
-- | Will |
-- | Jane |
-- | Bill |
-- | Zack |
-- +------+

Use leetcode_mysql;
Drop table Customer;
Create table Customer (id int, name varchar(25), referee_id int);
Insert into Customer (id, name, referee_id) 
	Values ('1', 'Will', Null)
    ,('2', 'Jane', Null)
    ,('3', 'Alex', '2')
    ,('4', 'Bill', Null)
    ,('5', 'Zack', '1')
    ,('6', 'Mark', '2');
    
select * from Customer;

# 1
select name 
from Customer
where referee_id not in (2) or referee_id is null;

# 2
select name
from Customer
where id not in (select id from customer where referee_id = "2")