--- Get how many time employe spend in project ---
select work_days, hours as work_hours from projEmp
where empID = 1 and projID = 2;

--- Witch employees are working in project ---
select e.name, pro.name, p.work_day, p.hours from projectEmp as p
inner join employees as e onp.empID = e.id
inner join projects as pro on p.projID = pro.id;


--- How many hours are spent on projects ---
--- For all projects ---
select pro.name, sum(p.hours) from projectEmp as p
inner join projects as pro on pro.id = p.projID
group by p.projID;

--- For 1 project ---
select pro.name, sum(p.hours) from projectEmp as p
inner join projects as pro on pro.id = p.projID
group by p.projID having p.projID = 1;


--- Activ project count ---
select count(p.id) as `active project count`
from projects as p where isActive = True;