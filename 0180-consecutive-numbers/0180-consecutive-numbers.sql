# Write your MySQL query statement below
# Write your MySQL query statement below
with CTE as (
    select num ,
    lead(num,1) over() num1,
    lead(num,2) over() num2

    from logs

)


select distinct num ConsecutiveNums from cte where num = num1 && num1 = num2