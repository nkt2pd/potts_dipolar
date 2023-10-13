#!/bin/bash



#SBATCH --job-name=potts_dipolar10

#SBATCH --ntasks=1

#SBATCH -A cherngroup

#SBATCH --mem=32G

#SBATCH -p standard

#SBATCH --cpus-per-task=1

#SBATCH --time=7-00:00:00

#SBATCH --array=1-2000

#SBATCH -o potts10sbatch.out


./potts_dipolar_Ising_singleTemp.exe 72 ${SLURM_ARRAY_TASK_ID}
