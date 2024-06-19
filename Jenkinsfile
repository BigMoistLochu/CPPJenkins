pipeline {
    agent any
    stages {
        stage("Checkout") {
            steps {
                git url: 'https://github.com/BigMoistLochu/CPPJenkins', branch: 'main'
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
