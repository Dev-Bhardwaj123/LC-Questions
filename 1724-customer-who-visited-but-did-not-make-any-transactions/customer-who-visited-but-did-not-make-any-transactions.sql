# Write your MySQL query statement below
SELECT customer_id,COUNT(customer_id) as count_no_trans
FROM Visits as A
LEFT JOIN
Transactions as B
ON A.visit_id=B.visit_id
WHERE B.visit_id IS NULL
GROUP BY customer_id