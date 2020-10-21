'''
Backward method to solve 1D reaction-diffusion equation:
    u_t = D * u_xx 
'''

import numpy as np
from scipy import sparse
import matplotlib.pyplot as plt
from scipy.sparse import diags



def FTCS_Dirichlet(M,N,xlims,tlims,dx,dt,initial_cond,bc1,bc2,D):
         
         # M= GRID POINTS on space interval
         # N= GRID POINTS on time interval
         # D = Diffusion coefficient
            
    x0,xL = xlims
    t0,tF = tlims
         
         
    # ----- Spatial discretization step -----
    dx = (xL - x0)/(M - 1)

    # ----- Time step -----
    dt = (tF - t0)/(N - 1)


    r = dt*D/dx**2


    # ----- Creates grids -----
    xspan = np.linspace(x0, xL, M)
    tspan = np.linspace(t0, tF, N)

    # ----- Initializes matrix solution U -----
    U = np.zeros((M, N))

    # ----- Initial condition -----
    U[:,0] = initial_cond(xspan)

    # ----- Dirichlet Boundary Conditions -----
    U[0,:] = bc1
    U[-1,:] = bc2

    for k in range(0, N-1):
        for i in range(1, M-1):
            U[i, k+1] = r*U[i-1, k] + (1-2*r)*U[i,k] + r*U[i+1,k] 
            
    return xspan,tspan,U

def BTCS_Dirichlet(M,N,xlims,tlims,dx,dt,initial_cond,bc1,bc2,D):
         
         # M= GRID POINTS on space interval
         # N= GRID POINTS on time interval
         # D = Diffusion coefficient
            
    x0,xL = xlims
    t0,tF = tlims
   

    # ----- Spatial discretization step -----
    dx = (xL - x0)/(M - 1)

    # ----- Time step -----
    dt = (tF - t0)/(N - 1)

    r = dt*D/dx**2


    xspan = np.linspace(x0, xL, M)
    tspan = np.linspace(t0, tF, N)

    main_diag = (1 + 2*r)*np.ones((1,M-2))
    off_diag = -r*np.ones((1, M-3))

    a = main_diag.shape[1]

    diagonals = [main_diag, off_diag, off_diag]

    A = sparse.diags(diagonals, [0,-1,1], shape=(a,a)).toarray()

     # ----- Initializes matrix U -----
    U = np.zeros((M, N))

    #----- Initial condition -----
    U[:,0] = initial_cond(xspan)

    #----- Dirichlet boundary conditions -----
    U[0,:] = bc1 
    U[-1,:] = 0.0

    for k in range(1, N):
    
        c = np.zeros((M-4,1)).ravel()
        b1 = np.asarray([r*U[0,k], r*U[-1,k]])
        b1 = np.insert(b1, 1, c)
        b2 = np.array(U[1:M-1, k-1])
        b = b1 + b2  # Right hand side
        U[1:M-1, k] = np.linalg.solve(A,b)  # Solve x=A\b

    return xspan,tspan,U

def BTCS_Neumann(xlims,tlims,dx,dt,initial,lBC,rBC,D):
         
         # M= GRID POINTS on space interval
         # N= GRID POINTS on time interval
         # D = Diffusion coefficient
            
    x0,xL = xlims
    t0,tF = tlims
   

    # ----- Spatial discretization step -----
    M = int((xL - x0)/dx + 1)

    # ----- Time step -----
    N = int((tF - t0)/dt + 1)

    r = dt*D/dx**2
    a = 1 + 2*r

    xspan = np.linspace(x0, xL, M)
    tspan = np.linspace(t0, tF, N)

    main_diag = (1 + 2*r)*np.ones((1,M))
    off_diag = -r*np.ones((1, M-1))
    
    a = main_diag.shape[1]

    diagonals = [main_diag, off_diag, off_diag]
    
    A = sparse.diags(diagonals, [0,-1,1], shape=(a,a)).toarray()
    A[0,1] = -2*r
    A[M-1,M-2] = -2*r
    
    # ----- Initializes matrix U -----
    U = np.zeros((M, N))

    #----- Initial condition -----
    U[:,0] = initial(xspan)

    #----- Neumann boundary conditions -----
    leftBC = np.arange(1, N+1)
    f = lBC(leftBC)

    rightBC = np.arange(1, N+1)
    g = rBC(rightBC)


    for k in range(1, N):
        
        c = np.zeros((M-2,1)).ravel()
        b1 = np.asarray([2*r*dx*f[k], 2*r*dx*g[k]])
        b1 = np.insert(b1, 1, c)
        b2 = np.array(U[0:M, k-1])
        b = b1 + b2  # Right hand side
        U[0:M, k] = np.linalg.solve(A,b)  # Solve x=A\b

    return xspan,tspan,U

def CrankNicolson_Dirichlet(xlims,tlims,dx,dt,initial,lBC,rBC,D):
         
         # M= GRID POINTS on space interval
         # N= GRID POINTS on time interval
         # D = Diffusion coefficient
            
    x0,xL = xlims
    t0,tF = tlims
   

    # ----- Spatial discretization step -----
    M = int((xL - x0)/dx + 1)

    # ----- Time step -----
    N = int((tF - t0)/dt + 1)
 

    alpha = dt*D/(2.0*dx**2)
    
    a0 = 1 + 2*alpha
    c0 = 1 - 2*alpha

    xspan = np.linspace(x0, xL, M)
    tspan = np.linspace(t0, tF, N)

    maindiag_a0 = a0*np.ones((1,M-2))
    offdiag_a0 = (-alpha)*np.ones((1, M-3))

    maindiag_c0 = c0*np.ones((1,M-2))
    offdiag_c0 = alpha*np.ones((1, M-3))

    #Left-hand side tri-diagonal matrix
    a = maindiag_a0.shape[1]
    diagonalsA = [maindiag_a0, offdiag_a0, offdiag_a0]
    A = sparse.diags(diagonalsA, [0,-1,1], shape=(a,a)).toarray()
    
    

    #Right-hand side tri-diagonal matrix
    c = maindiag_c0.shape[1]
    diagonalsC = [maindiag_c0, offdiag_c0, offdiag_c0]
    
    Arhs = sparse.diags(diagonalsC, [0,-1,1], shape=(c,c)).toarray()
    

    # ----- Initializes matrix U -----
    U = np.zeros((M, N))
    
    
    # ----- Initial condition -----
    U[:,0] = initial(xspan)
    
    
    # ----- Boundary conditions -----

    U[0,:] = lBC;
    U[-1,:] = rBC;
    
   
    for k in range(1, N):
        
        ins = np.zeros((M-4,1)).ravel()
        
        b1 = np.asarray([alpha*U[0,k]+alpha*U[0,k-1],alpha*U[-1,k]+alpha*U[-1,k-1]])
        
        b1 = np.insert(b1, 1, ins)
        
        b2 = np.matmul(Arhs, np.array(U[1:M-1, k-1]))
        
        b = b1 + b2  # Right hand side
        
        U[1:M-1, k] = np.linalg.solve(A,b)  # Solve x=A\b

    return xspan,tspan,U
