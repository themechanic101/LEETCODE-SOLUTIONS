# Write your MySQL query statement below
SELECT name from Employee
where id IN (
    SELECT managerId
    From Employee
    GROUP BY managerId
    HAVING COUNT(*)>=5
);