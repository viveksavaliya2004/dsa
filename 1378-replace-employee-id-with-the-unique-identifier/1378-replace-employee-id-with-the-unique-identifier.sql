# Write your MySQL query statement below
SELECT a.unique_id , es.name 
FROM Employees es
LEFT JOIN EmployeeUNI a 
ON es.id = a.id;
