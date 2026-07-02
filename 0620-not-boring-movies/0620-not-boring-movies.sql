# Write your MySQL query statement below
select * from Cinema 
WHERE id%2!=0 && description!='boring'
order By rating DESC;