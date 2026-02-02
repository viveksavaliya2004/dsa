# Write your MySQL query statement below
# Write your MySQL query statement below
-- select s1.score ,(select count(distinct score) from scores s2 
-- where s2.score>=s1.score) as "rank" from scores s1 
-- order by s1.score desc

SELECT score, (DENSE_RANK() OVER (ORDER BY score DESC)) as "rank" FROM Scores 
ORDER BY score DESC;