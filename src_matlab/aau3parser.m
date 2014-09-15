%% AA3U Control Format parser
clc; clear all;

%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
% AAU3 Parser and Data Reader v0.1
% Benjamin Krebs og Rasmus Christensen
% Last edit: 15/9/2014, by: RLC: rlc@es.aau.dk
% 
% The controller structure is defined by the state vector X, which is given
% as X_i = [thetaB, thetaW, dthetaW] with:
% thetaB    = angle of the body
% thetaW    = angle of the reaction wheel
% dthetaW   = angular velocity of the reaction wheel
%
% The denoted i denotes the delay of the system as X[n-i], if the delay is 
% one, the notation is X_1 and if it is 2 the notation is X_2, etc..
%
% It should work for any input function (even fancy ones such as Cholesky
% Decomposition) - if it doesn't either fix it, or write us an e-mail and
% we will. 
% 
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

%% System Variable Declarations:
% Currently only specificed up to X[n-3]
X_0 = sym('X_0',[3 1]);
X_1 = sym('X_1',[3 1]);
X_2 = sym('X_2',[3 1]);
X_3 = sym('X_3',[3 1]);

%% Input Definnition:
u   =   magic(3)*X_0 + magic(3)*X_1 + sin(X_0) + 3.14;% Some user input function.

%% Input Parser:
%path = 'smb://aau3.lab.es.aau.dk/<some file that manages the controller>.txt';
path = 'tst.txt'; % Test file, delete in final version
[writeId, errMsg] = fopen(path,'w');

if (writeId) > 0;
    for j = 1:length(u)
        fprintf(writeId,'%s\n', char(u(j)));
    end
    fclose(writeId);
else
    fprintf('No Connection to the Raspberry Pi - duckduckduck?\n');
    fprintf(errMsg)
end