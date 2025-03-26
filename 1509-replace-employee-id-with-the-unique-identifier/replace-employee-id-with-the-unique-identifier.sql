# Write your MySQL query statement below
SELECT unique_id, name
FROM Employees AS em
LEFT JOIN EmployeeUNI AS eu
ON em.id=eu.id