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
                cd AplikacjaCPP/build
                cmake ..
                make
                '''
            }
        }
        stage("Unit Test") {
            steps {
                sh '''
                chmod +x runTests
                ./runTests
                '''
            }
        }
    }
}
