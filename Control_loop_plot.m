Output = Output';
n = length(Output);
dt = 1/100;
ref = 30;
x_des = ones(n,1)*ref;

%Time
time = linspace(0,n*dt,n);
time = time';

figure();
plot(time,x_des, LineWidth=1.5);
hold on
plot(time, Output, LineWidth=1.5);
legend('x-des','output');
xlabel('time');
