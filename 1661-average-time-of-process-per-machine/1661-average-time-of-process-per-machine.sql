# Write your MySQL query statement below
SELECT a1.machine_id, ROUND(AVG(a2.timestamp-a1.timestamp),3) AS processing_time
FROM Activity a1 JOIN Activity a2
ON a1.machine_id = a2.machine_id and a1.activity_type = 'start' AND a2.activity_type = 'END'
GROUP BY a1.machine_id;