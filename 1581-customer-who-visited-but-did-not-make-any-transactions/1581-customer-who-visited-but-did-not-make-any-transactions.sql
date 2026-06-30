SELECT v.customer_id,count(v.visit_id) AS count_no_trans
FROM  Visits v
LEFT JOIN Transactions as t
    on v.visit_id = t.visit_id
WHERE t.transaction_id IS Null
GROUP BY customer_id