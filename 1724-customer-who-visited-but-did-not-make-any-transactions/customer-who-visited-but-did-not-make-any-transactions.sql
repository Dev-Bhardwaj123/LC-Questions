# Write your MySQL query statement below
SELECT customer_id,COUNT(customer_id) AS count_no_trans
FROM Visits AS V
LEFT JOIN Transactions AS T
ON V.visit_id=T.visit_id
WHERE T.visit_id IS NULL
group by customer_id
