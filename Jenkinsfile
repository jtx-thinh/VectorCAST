pipeline {
  agent {
    node {
      label 'VC2020'
    }

  }
  stages {
    stage('Stage-01') {
      steps {
        build(job: 'TestCampaign', quietPeriod: 3)
      }
    }

  }
}