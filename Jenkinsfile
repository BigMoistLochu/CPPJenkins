pipeline {
    agent any
    stages {
        stage("Checkout") {
            steps {
                git url: 'https://github.com/BigMoistLochu/CPPJenkins', branch: 'main'
            }
        }
        stage("Compile and Build") {
            steps {
                sh '''
                cd AplikacjaCPP
                mkdir -p build
                cd build
                rm -rf *
                cmake ..
                make
                '''
            }
        }
        stage("Unit Test") {
            steps {
                sh '''
                cd AplikacjaCPP/build
                chmod +x runTests
                ./runTests
                '''
            }
        }
    }
}
